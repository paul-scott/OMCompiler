/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Linköping University,
 * Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3
 * AND THIS OSMC PUBLIC LICENSE (OSMC-PL).
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES RECIPIENT'S
 * ACCEPTANCE OF THE OSMC PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linköping University, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#ifndef BASE_ARRAY_H_
#define BASE_ARRAY_H_

#include "openmodelica.h"
#include <stdlib.h>
#include <stdarg.h>

/* Settings the fields of a base_array */
void base_array_create(base_array_t *dest, void *data, int ndims, va_list ap);

/* Allocation of a vector */
void simple_alloc_1d_base_array(base_array_t *dest, int n, void *data);

/* Allocation of a matrix */
void simple_alloc_2d_base_array(base_array_t *dest, int r, int c, void *data);

/* Allocate array */
size_t alloc_base_array(base_array_t *dest, int ndims, va_list ap);

/* Number of elements in array. */
size_t base_array_nr_of_elements(const base_array_t *a);

/* Clones fields */
void clone_base_array_spec(const base_array_t *source, base_array_t *dest);

void clone_reverse_base_array_spec(const base_array_t* source, base_array_t* dest);

int ndims_base_array(const base_array_t* a);
int size_of_dimension_base_array(const base_array_t a, int i);

/* Helper functions */
int base_array_ok(const base_array_t *a);
void check_base_array_dim_sizes(const base_array_t * const *elts, int n);
void check_base_array_dim_sizes_except(int k, const base_array_t * const *elts, int n);
int base_array_shape_eq(const base_array_t *a, const base_array_t *b);
int base_array_one_element_ok(const base_array_t *a);

size_t calc_base_index_spec(int ndims, const _index_t* idx_vec,
                            const base_array_t *arr, const index_spec_t *spec);
size_t calc_base_index(int ndims, const _index_t *idx_vec, const base_array_t *arr);
size_t calc_base_index_va(const base_array_t *source, int ndims, va_list ap);

int index_spec_fit_base_array(const index_spec_t *s, const base_array_t *a);

#endif /* BASE_ARRAY_H_ */
