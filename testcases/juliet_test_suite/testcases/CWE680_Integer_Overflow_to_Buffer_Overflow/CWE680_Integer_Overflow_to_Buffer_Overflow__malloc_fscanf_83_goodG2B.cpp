/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_goodG2B.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83
{
CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_goodG2B::CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_goodG2B(int dataCopy)
{
    data = dataCopy;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
}

CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_goodG2B::~CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_83_goodG2B()
{
    {
        size_t i;
        int *intPointer;
        /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
         * so that the for loop doing the initialization causes a buffer overflow */
        intPointer = (int*)malloc(data * sizeof(int));
        for (i = 0; i < (size_t)data; i++)
        {
            intPointer[i] = 0; /* Potentially writes beyond the boundary of intPointer */
        }
        printIntLine(intPointer[0]);
        free(intPointer);
    }
}
}
#endif /* OMITGOOD */
