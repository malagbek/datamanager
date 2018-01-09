#ifndef DATAMANAGER_BUFFER_H
#define DATAMANAGER_BUFFER_H

#include "types_c.h"

class Buffer
{
public:
    virtual void ~Buffer() {}

    /// number of dimensions
    virtual int NumDimensions() const = 0;
    /// length of given dimension
    virtual int DimLength(int dimension) const = 0;
    /// total number of stored elements
    virtual int NumElements() const = 0;
    /// type of stored data
    virtual Scalar_t ElementType() const = 0;
    /// pointer to data start
    virtual void * Data() const = 0;
    /// size of individual element in bytes 
    virtual int ElementBytes() const = 0;
    /// whether buffer properties can be changed or not
    virtual int IsReadOnly() const = 0;
    
    /// sets number of dimensions
    virtual void NumDimensions(int count) = 0;
    /// sets dimension length
    virtual void DimLength(int dim, int length) = 0;
    /// sets element type
    virtual void ElementType(Scalar_t type) = 0;
    /// sets data pointer
    virtual void Data(void * ptr) = 0;
};

#endif
