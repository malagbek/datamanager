#ifndef DATAMANAGER_TYPES_H
#define DATAMANAGER_TYPES_H

enum Scalar_t
{
    Unknown,
    Boolean,
    Integer,
    Float,
    Double,
    String
};

/// Identifier used to address individual scalars and arrays
struct identifier_t
{
    /// name of group
    const char * group;
    /// content name
    const char * data;
};

/// Data buffer
struct buffer_t
{
    /// underlying data type
    Scalar_t type;
    /// number of elements
    int size;
    /// pointer to first element
    void * data;
};


#endif
