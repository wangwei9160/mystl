/*

第二级配置器：
第二级配置器共维护16个free-lists，各自管理的大小分别为8，16,24,32,40,48,56,64,72，80,88，96,104,112,120,128bytes。
union obj{
    union obj * free_list_link;
    char client_data[1] ;  
}
static obj * volatitle free_list[]
static size_t FREELIST_INDEX(size_t bytes) 根据区块大小，决定使用第几号free-list,n从1算起
static void * refill(size_t n) 返回一个大小为n的对象，并可能加入大小为n的其他区块到free list
static char * chunk_alloc(size_t size , int &nobjs) 配置一大块空间，可容纳nobjs个大小为size的区块

start_free 内存池起始位置。只能在chunk_alloc()中变化
end_free 内存池结束位置。只能在chunk_alloc()中变化
heap_size

allocate(size_t n)
deallocate(void *p , size_t n)
reallocate(void *p , size_t old_size , size_t new_size)

*/