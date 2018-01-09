#ifndef DATAMANAGER_MANAGER_H
#define DATAMANAGER_MANAGER_H

#include "types.h"
#include "buffer.h"

class Manager
{
public:
    virtual ~Manager() {}
    
    /// number of stored scalars
    virtual int GetNumScalars() const = 0;
    /// name of scalar at given internal offset
    virtual Identifier GetScalarID(int index) const = 0;
    /// whether scalar with given name exists
    virtual int HasScalar(Identifier id) const = 0;
    /// scalar type
    virtual Scalar_t GetScalarType(Identifier id) const = 0;
    /// scalar content as string
    virtual const char * GetScalarAsString(identifier_t id) const = 0;
    /// scalar content as number
    virtual double GetScalarAsNumber(identifier_t id) const = 0;
    
    /// set or replace scalar as a string
    virtual int SetScalar(Identifier id, const char * content) = 0;
    /// set or replace scalar as number of given type
    virtual int SetScalar(Identifier id, Scalar_t type, double value) = 0;
    /// remove scalar
    virtual int RemoveScalar(Identifier id) = 0;
    
    /// number of stored arrays
    virtual int GetNumArrays() const = 0;
    /// name of array at given internal offset
    virtual Identifier GetArrayID(int index) const= 0;
    /// whether array with given name exists
    virtual int HasArray(Identifier id) const = 0;
    /// type of given array
    virtual Scalar_t GetArrayType(Identifier id) const = 0;
    /// access to array internals
    virtual Buffer_t * GetArray(Identifier id) const = 0;
    
    /// set or replace array
    virtual int SetArray(Identifier id, Buffer_t * buffer, int copy) = 0;
    /// remove array
    virtual int RemoveArray(Identifier id) = 0;
    
    /// retrieve last error message
    virtual const char * GetLastError() const = 0;
    /// clear last error message
    virtual void ClearLastError() = 0;
};

#endif
