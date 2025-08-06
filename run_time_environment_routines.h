#ifndef RUN_TIME_ENVIRONMENT_ROUTINES_H
#define RUN_TIME_ENVIRONMENT_ROUTINES_H

#include <stdio.h>
#include <omp.h>

// 1. omp_get_num_threads
void fn_rter_omp_get_num_threads() {
#pragma omp parallel
    {
        printf("[Thread %d] Total Threads: %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
}

// 2. omp_get_thread_num
void fn_rter_omp_get_thread_num() {
#pragma omp parallel
    {
        printf("Thread ID: %d\n", omp_get_thread_num());
    }
}

// 3. omp_get_max_threads
void fn_rter_omp_get_max_threads() {
    printf("Max threads: %d\n", omp_get_max_threads());
}

// 4. omp_get_num_procs
void fn_rter_omp_get_num_procs() {
    printf("Available processors: %d\n", omp_get_num_procs());
}

// 5. omp_in_parallel
void fn_rter_omp_in_parallel() {
#pragma omp parallel
    {
        printf("Thread %d: In parallel? %d\n", omp_get_thread_num(), omp_in_parallel());
    }
}

// 6. omp_set_num_threads
void fn_rter_omp_set_num_threads() {
    omp_set_num_threads(4);
#pragma omp parallel
    {
        printf("Thread %d after setting num threads.\n", omp_get_thread_num());
    }
}

// 7. omp_get_dynamic
void fn_rter_omp_get_dynamic() {
    printf("Dynamic: %d\n", omp_get_dynamic());
}

// 8. omp_set_dynamic
void fn_rter_omp_set_dynamic() {
    omp_set_dynamic(1);
    printf("Set dynamic adjustment enabled.\n");
}

// 9. omp_get_nested
void fn_rter_omp_get_nested() {
    printf("Nested parallelism: %d\n", omp_get_nested());
}

// 10. omp_set_nested
void fn_rter_omp_set_nested() {
    omp_set_nested(1);
    printf("Nested parallelism enabled.\n");
}

// 11. omp_get_schedule
void fn_rter_omp_get_schedule() {
    omp_sched_t kind;
    int modifier;
    omp_get_schedule(&kind, &modifier);
    printf("Schedule type: %d, modifier: %d\n", kind, modifier);
}

// 12. omp_set_schedule
void fn_rter_omp_set_schedule() {
    omp_set_schedule(omp_sched_dynamic, 4);
    printf("Schedule set to dynamic, chunk size 4.\n");
}

// 13. omp_get_thread_limit
void fn_rter_omp_get_thread_limit() {
    printf("Thread limit: %d\n", omp_get_thread_limit());
}

// 14. omp_get_max_active_levels
void fn_rter_omp_get_max_active_levels() {
    printf("Max active levels: %d\n", omp_get_max_active_levels());
}

// 15. omp_set_max_active_levels
void fn_rter_omp_set_max_active_levels() {
    omp_set_max_active_levels(4);
    printf("Set max active levels to 4.\n");
}

// 16. omp_get_level
void fn_rter_omp_get_level() {
#pragma omp parallel
    {
        printf("Thread %d: Nesting level: %d\n", omp_get_thread_num(), omp_get_level());
    }
}

// 17. omp_get_ancestor_thread_num
void fn_rter_omp_get_ancestor_thread_num() {
#pragma omp parallel
    {
        int level = omp_get_level();
        printf("Thread %d: Ancestor at level %d is thread %d\n",
            omp_get_thread_num(), level, omp_get_ancestor_thread_num(level));
    }
}

// 18. omp_get_team_size
void fn_rter_omp_get_team_size() {
#pragma omp parallel
    {
        printf("Thread %d: Team size at level 0: %d\n", omp_get_thread_num(), omp_get_team_size(0));
    }
}

// 19. omp_get_active_level
void fn_rter_omp_get_active_level() {
#pragma omp parallel
    {
        printf("Thread %d: Active level: %d\n", omp_get_thread_num(), omp_get_active_level());
    }
}

// 20. omp_in_final
void fn_rter_omp_in_final() {
#pragma omp parallel
    {
#pragma omp single
        {
#pragma omp task final(1)
            {
                printf("In final task: %d\n", omp_in_final());
            }
        }
    }
}

// 21. omp_get_cancellation
void fn_rter_omp_get_cancellation() {
    printf("Cancellation supported: %d\n", omp_get_cancellation());
}

// 22. omp_get_default_device
void fn_rter_omp_get_default_device() {
    printf("Default device: %d\n", omp_get_default_device());
}

// 23. omp_set_default_device
void fn_rter_omp_set_default_device() {
    omp_set_default_device(1);
    printf("Set default device to 1.\n");
}

// 24. omp_get_num_devices
void fn_rter_omp_get_num_devices() {
    printf("Number of devices: %d\n", omp_get_num_devices());
}

// 25. omp_get_num_teams
void fn_rter_omp_get_num_teams() {
#pragma omp target teams
    {
        printf("Number of teams: %d\n", omp_get_num_teams());
    }
}

// 26. omp_get_team_num
void fn_rter_omp_get_team_num() {
#pragma omp target teams
    {
        printf("Team number: %d\n", omp_get_team_num());
    }
}

// 27. omp_get_num_threads (Target Teams)
void fn_rter_omp_get_num_threads_target() {
#pragma omp target teams distribute parallel for
    for (int i = 0; i < 4; i++) {
        printf("Thread %d out of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
}

#endif
