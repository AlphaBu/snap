#ifndef __ACTION_INTERSECT_H__
#define __ACTION_INTERSECT_H__

/*
 * Copyright 2016, 2017, International Business Machines
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <snap_types.h>

#ifdef __cplusplus
extern "C" {
#endif


#define INTERSECT_ACTION_TYPE 0x10141005

#define END_SIGN 0xFFFFFFFF
#define NUM_TABLES  2
#define MAX_TABLE_SIZE (uint64_t)(1<<30)

#define HT_ENTRY_NUM_EXP 24
#define HT_ENTRY_NUM (1<<HT_ENTRY_NUM_EXP)

#define DIRECT_METHOD 0
#define HASH_METHOD 1
#define SORT_METHOD 2


typedef struct intersect_job {
	struct snap_addr src_tables_host[NUM_TABLES];	 /* input tables */
	struct snap_addr src_tables_ddr[NUM_TABLES];	 /* input tables */
	struct snap_addr result_table;             /* output table */
    uint32_t step;
    uint32_t method;
} intersect_job_t;

typedef char value_t[64];
typedef unsigned int ptr_t;

void copyvalue(value_t dst, value_t src);
int cmpvalue(const value_t src1, const value_t src2);
uint32_t run_sw_intersection(int method, value_t * table1, uint32_t n1, value_t* table2, uint32_t n2, value_t * result_array);

struct entry_t
{
    value_t data;
    struct entry_t * next;
}entry_t;


#ifdef __cplusplus
}
#endif
#endif	/* __ACTION_INTERSECT_H__ */
