#ifndef DATAMANAGER_TYPES_H
#define DATAMANAGER_TYPES_H

enum scalar_t
{
    unknown,
    boolean,
    integer,
    float,
    double,
    string
};

/// Identifier used to address individual scalars and arrays
struct identifier_t
{
    /// name of element
    const char * element;
    /// data descriptor
    const char * data;
};

/// Data buffer
struct buffer_t
{
    /// underlying data type
    scalar_t type;
    /// number of elements
    int size;
    /// pointer to first element
    void * data;
};

// opaque geometry type
struct geometry_t;

// opaque array type
struct array_t;

// opaque data manager type
struct datamanager_t;

extern "C"
{
    /// creates new instance of geometry object
    geometry_t*  create_geometry();
    /// destroys geometry instance
    void destroy_geometry(geometry_t*);
    
    /// total number of dimensions
    int get_num_dims(geometry_t*);
    /// number of elements in given direction
    int get_dim_length(geometry_t*, int dim);
    /// total number of elements
    int get_total_length(geometry_t*);
    /// change number of dimensions, returns zero for errors
    int set_num_dims(geometry_t*, int num_dims);
    /// change dim length, returns zero for errors
    void set_dim_length(geometry_t*, int dim, int dim_length);
    
    array_t create_array();
    void destroy_array(array_t*);
    int set_buffer(array_t*, buffer_t);
    buffer_t get_buffer(array_t*);
    geometry_t* get_geometry(array_t*);
    int set_geometry(array_t*, geometry_t*);
    
    /// creates new instance of data manager object
    datamanager_t* create_datamanager();
    /// destroys instance of data manager object
    void destroy_datamanager(datamanager_t*);
    
    /// number of stored scalar values
    int get_num_scalars(datamanager_t *);
    /// identifier of scalar at given offset
    identifier_t get_scalar_id(datamanager_t *, int index);    
    /// returns non-zero if scalar with given name exists
    int has_scalar(datamanager_t *, identifier_t);
    /// type of scalar with given identifier
    scalar_t get_scalar_type(datamanager *, identifier_t);
    /// get numeric value of given scalar
    double get_scalar_num(datamanager_t *, identifier_t);
    /// get string value of given scalar
    const char* get_scalar_str(datamanager_t *, identifier_t);
    /// set numeric scalar value
    int set_scalar(datamanager_t *, identifier_t, double v);
    /// set string scalar value
    int set_scalar(datamanager_t *, identifier_t, const char *str);
    /// remove scalar
    int remove_scalar(datamanager_t *, identifier_t);
    
    /// number of stored arrays
    int get_num_arrays(datamanager_t *);
    /// identifier of array at given offset
    identifier_t get_array_id(datamanager_t *, int index);
    /// returns non-zero if array with given identifier exists
    int has_array(datamanager_t *, identifier_t);
    /// type of array
    scalar_t get_array_type(datamanager_t *, identifier_t);
    /// number of elements for given array
    int get_array_size(datamanager_t *, identifier_t);
    /// geometry of given array
    geometry_t* get_array_geometry(datamanager_t *, identifier_t);
    /// adds or replaces array
    int set_array(datamanager_t *, identifier_t, buffer_t, int copy);
    /// removes array
    int remove_array(datamanager_t *, identifier_t);
    
    /// creates deep copy of given data manager
    datamanager_t * clone(datamanager_t*);
    
    /// clears all scalars and arrays
    int clear(datamanager_t*);
    
    /// last error message
    const char * last_error(datamanager_t*);
    /// clear last error message
    void clear_error(datamanager_t*);
}

#endif
