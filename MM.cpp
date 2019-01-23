#include <iostream>
#include"MM.h"
#include"Circle.h"
#include"Triangle.h"

MemoryManager mm;

MemoryManager::MemoryManager() {
    CirclePool = (char*) malloc (POOL_SIZE * sizeof(Circle));
    TrianglePool = (char*) malloc (POOL_SIZE * sizeof(Triangle));
    
    for (int i = 0; i < POOL_SIZE; i++) {
        CircleSet.insert(i);
        TriangleSet.insert(i);
    }
}

void* MemoryManager::alloc(size_t size) {
    if(size == sizeof(Circle)) {
        if(!CircleSet.empty()) {
            int block_index = *(CircleSet.begin());
            CircleSet.erase(CircleSet.begin());
            return CirclePool + sizeof(Circle) * block_index;
        }
        else {
            std::cerr << "Out of memory.\n";
        }
    }
    else if(size == sizeof(Triangle)) {
        if(!TriangleSet.empty()) {
            int block_index = *(TriangleSet.begin());
            TriangleSet.erase(TriangleSet.begin());
            return TrianglePool + sizeof(Triangle) * block_index;
        }
        else {
            std::cerr << "Out of memory.\n";
        }
        
    }
    return nullptr;
}

void MemoryManager::free(void* block) {
    if(block != NULL){
        if((char*)block >= CirclePool && (char*)block < CirclePool + POOL_SIZE*sizeof(Circle)){
            int block_index = ((char*)block - CirclePool)/sizeof(Circle);
            CircleSet.insert(block_index);
        }
        else if((char*)block >= TrianglePool && (char*)block < TrianglePool + POOL_SIZE*sizeof(Triangle)){
            int block_index = ((char*)block - TrianglePool)/sizeof(Triangle);
            TriangleSet.insert(block_index);
        }
    }
}

int MemoryManager::free_circles() {
    return CircleSet.size();
}

int MemoryManager::free_triangles() {
    return TriangleSet.size();
}

MemoryManager::~MemoryManager() {
    free(CirclePool);
    free(TrianglePool);
}