//
//  RootFinding.h
//  libdatafun
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

typedef struct _UnidimensionalRootFindingParameters{
    int max_iterations;
    double lower_bound;
    double upper_bound;
    double abs_error;
    double rel_error;
} UnidimensionalRootFindingParameters;

typedef struct _MultidimensionalRootFinderParams{
    const gsl_multiroot_fsolver_type * solver_type;

    double abs_error;
    double rel_error;
    int max_iterations;
} MultidimensionalRootFinderParams;

// Find unidimensional roots. If the provided function does not
// straddle the root, return -1. Return 0 on success.
int
UnidimensionalRootFinder(gsl_function  *F,
                         UnidimensionalRootFindingParameters  params,
                         double         		                 *return_result);

int
MultidimensionalRootFinder(gsl_multiroot_function  *f,
                           MultidimensionalRootFinderParams *params,
                           const int                dimension,
                           gsl_vector              *initial_guess,
                           gsl_vector              *results);

#endif /* RootFinding_h */

