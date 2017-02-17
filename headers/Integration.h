//
//  Integration.h
//  NJLv
//
//  Created by Clebson Graeff on 2017-02-14.
//  Copyright © 2017 Clebson Graeff. All rights reserved.
//

#ifndef Integration_h
#define Integration_h

#include <gsl/gsl_integration.h>

typedef struct _IntegratorParameters{
    double lower_limit;
    double upper_limit;
    double abs_error;
    double rel_error;
    int max_interval_num;
    int max_sub_interval;
    int integration_key;
} IntegratorParameters;

double OnedimensionalIntegrator(gsl_function * F,
								IntegratorParameters parameters);

#endif /*Integration_h */
