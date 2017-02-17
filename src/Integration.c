//
//  Integration.c
//  libdatafun
//
//  Created by Clebson Graeff on 2017-02-14.
//  Copyright © 2017 Clebson Graeff. All rights reserved.
//

#include "Integration.h"

double OnedimensionalIntegrator(gsl_function * F,
                                IntegratorParameters parameters)
{
    gsl_integration_workspace * workspace =
    gsl_integration_workspace_alloc(parameters.max_interval_num);

    double integral = 0;
    double abserr;
    gsl_integration_qag(F,
                        parameters.lower_limit,
                        parameters.upper_limit,
                        parameters.abs_error,
                        parameters.rel_error,
                        parameters.max_sub_interval,
                        parameters.integration_key,
                        workspace,
                        &integral,
                        &abserr);

    gsl_integration_workspace_free(workspace);

    return integral;
}
