
#include "TAllocationBlock.h"
TAllocationBlock::TAllocationBlock(size_t size, size_t count) : _size(size), _count(count) {
    _used_blocks = (unsigned char *)malloc(_size*_count);
    for (size_t i = 0; i < _count; i++) {
        void *ptr = _used_blocks+i*size;
        _free_blocks.PushBack(ptr);
    }
    _free_count = _count;
    std::cout << "TAllocationBlock: Memory init\n";
}
void * TAllocationBlock::allocate() {
    void *result = nullptr;
    if (_free_count > 0) {
        result = _free_blocks.Front();
        _free_blocks.PopFront();
        _free_count--;
        std::cout << "TAllocationBlock: Allocate " << (_count-_free_count)
                                                   << " of " << _count << std::endl;

    } else {
        std::cout << "TAllocationBlock: No memory exception :-)" << std::endl;
    }
    return result;
}
bool TAllocationBlock::Find(void *pointer) {
    return (_used_blocks <= pointer && pointer <= _used_blocks + _size*_count);
}
void TAllocationBlock::deallocate(void *pointer) {
    std::cout << "TAllocationBlock: Deallocate block\n";
    _free_blocks.PushBack(pointer);
    pointer = nullptr;
    std::cout << "Freee count: " << _free_count+1 <<std::endl;
    _free_count++;
}
bool TAllocationBlock::has_free_blocks() {
    return _free_count>0;
}
TAllocationBlock::~TAllocationBlock() {
    std::cout << "Desktructor: Memory freed\n";
    free(_used_blocks);
}
