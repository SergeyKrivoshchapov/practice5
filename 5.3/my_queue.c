#include "my_queue.h"

int enqueue(WIFI_queue* queue, WIFI* data) 
{
    WIFI_item* new_item = (WIFI_item*)malloc(sizeof(WIFI_item));
    if (!new_item)
    {
	printf("Can't create new item");
	return 1;
    }
    new_item->data = data;
    if (queue->head == NULL)
    {
        new_item->next = queue->head;
        queue->head = new_item;
        new_item->prev = NULL;
        return 0;
    }
    new_item->next = queue->head;
    queue->head->prev = new_item;
    queue->head = new_item;
    return 0;

}

WIFI* dequeue(WIFI_queue* queue) 
{
    WIFI* data = NULL;
    if (queue->head == NULL) 
    {
        printf("Empty.\n");
        return data;
    }
    
    struct WIFI_item* temp = queue->head;

    while (temp->next) temp = temp->next;
    
    data = temp->data;
    
    if (temp->prev) temp->prev->next = NULL;
    else queue->head = NULL;
    
    free(temp);
    temp = NULL;
    
    return data;

}

void extract_data(WIFI_queue* queue)
{
    WIFI* data = dequeue(queue);
    if (data != NULL)
    {
        printf("Extracted from queue: \n");
        print_struct(data);
    }
}


void print_queue(const WIFI_queue* queue) 
{
    WIFI_item* current = queue->head;
    while (current != NULL) 
    {
        print_struct(current->data);
        current = current->next;
    }
}

void delete_queue(WIFI_queue* queue) 
{
    while (queue->head != NULL) dequeue(queue);
}

// error = return -1
int write_queue_tofile(const char* filename, WIFI_queue* queue)
{
    int count = 0; 
    WIFI_item* current = queue->head;
    while (current)
    {
        count++;
        current = current->next;
    }

    WIFI* routers = malloc(sizeof(WIFI) * count);
    if (!routers)
    {
        printf("error to allocate\n");
        return -1;
    }

    current = queue->head;
    for (int i = 0; i < count; i++)
    {
        copy_struct(current->data, &routers[i]);
        current = current->next;
    }

    int wrote = write_arraytofile(filename, routers, count);
    free(routers);
    return wrote;
}

// error = return 1
int read_queue_fromfile(const char* filename, WIFI_queue* queue)
{
    int fd = open(filename, O_RDONLY);
    if (fd == - 1)
    {
        printf("error opening file\n");
        return 1;
    }
    printf("file opened");

    int size = lseek(fd, 0, SEEK_END);
    int count = size / sizeof(WIFI);

    lseek(fd, 0, SEEK_SET);

    WIFI* routers = malloc(sizeof(WIFI) * count);
    if (!routers)
    {
        printf("error to allocate\n");
        return 1;
    }

    if (read(fd, routers, size) == -1)
    {
        printf("error reading file\n");
        return 1;
    }
    printf("file read\n");

    if (close(fd) == -1)
    {
        printf("error closing\n");
    }
    printf("file closed\n");

    for (int i = count - 1; i >= 0; i--)
    {
        WIFI* router = dynamic_struct_create(routers[i].vendor, routers[i].port_count, routers[i].has_5G);
        if (!router || enqueue(queue, router) == 1)
        {
            printf("error adding to queue\n");
            free(routers);
            delete_queue(queue);
            return 1;
        }
    }

    free(routers);
    return 0;
}
