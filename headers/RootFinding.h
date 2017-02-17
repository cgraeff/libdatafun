//
//  RootFinding.h
//  NJLv
//
//  Created by Clebson Graeff on 2017-02-14.
//  Copyright © 2017 Clebson Graeff. All rights reserved.
//

#ifndef RootFinding_h
#define RootFinding_h

#include <gsl/gsl_roots.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_vector.h>

// Find unidimensional roots. If the provided function does not
// straddle the root, return -1. Return 0 on success.
int UnidimensionalRootFinder(gsl_function   *F,
                             double          lower_bound,
                             double          upper_bound,
                             double          abs_error,
                             double          rel_error,
                             int             max_iterations,
                             double         *return_result);

int MultidimensionalRootFinder(const int                dimension,
                               gsl_multiroot_function  *f,
                               gsl_vector              *initial_guess,
                               double                   abs_error,
                               double                   rel_error,
                               int                      max_iterations,
                               gsl_vector              *results);

#endif /* RootFinding_h */

