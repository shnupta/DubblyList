#include <DubblyList.h>
#include "minunit.h"
#include <assert.h>

static DubblyList *list = NULL;

char *test_create()
{
    list = create_dubbly_list();
    mu_assert(list != NULL, "Failed to create list.");

    return NULL;
}

char *test_slap()
{
    dub_slap(list, 44);
    mu_assert(list->tail->value == 44, "Wrong tail value after slap.");

    dub_slap(list, 123);
    mu_assert(list->tail->value == 123, "Wrong tail value after slap.");

    dub_slap(list, 6);
    mu_assert(list->tail->value == 6, "Wrong tail value after slap.");

    dub_slap(list, 9);
    mu_assert(list->tail->value == 9, "Wrong tail value after slap.");

    dub_slap(list, 42);
    mu_assert(list->tail->value == 42, "Wrong tail value after slap.");

    dub_slap(list, 96);
    mu_assert(list->tail->value == 96, "Wrong tail value after slap.");

    return NULL;
}

char *test_shift()
{
    dub_shift(list, 18);
    mu_assert(list->head->value == 18, "Wrong head value after shift.");

    dub_shift(list, 9);
    mu_assert(list->head->value == 9, "Wrong head value after shift.");

    dub_shift(list, 0);
    mu_assert(list->head->value == 0, "Wrong head value after shift.");

    return NULL;
}

char *test_pop()
{
    dub_pop(list);
    mu_assert(list->tail->value == 42, "Wrong tail value after pop.");

    dub_pop(list);
    mu_assert(list->tail->value == 9, "Wrong tail value after pop.");

    return NULL;
}

char *test_slice()
{
    dub_slice(list);
    mu_assert(list->head->value == 9, "Wrong head value after slice.");

    dub_slice(list);
    mu_assert(list->head->value == 18, "Wrong head value after slice.");

    return NULL;
}

char *test_length()
{
    mu_assert(dub_length(list) == 5, "Wrong length returned.");

    return NULL;
}

char *test_for_forwards()
{
    printf("Forwards...\n");
    for_dubbly(list, head, next, cur_one) {
        printf("%d\n", cur_one->value);
    }

    return NULL;
}

char *test_for_backwards()
{
    printf("Backwards...\n");
    for_dubbly(list, tail, prev, cur_two) {
        printf("%d\n", cur_two->value);
    }

    return NULL;
}

char *test_clear()
{
    dub_clear(list);
    mu_assert(list->head == NULL && list->tail == NULL, "Failed to clear (still have values other than NULL).");

    return NULL;
}

char *test_destroy()
{
    dub_destroy(list);
    mu_assert(list == NULL, "Failed to destroy list (not NULL).");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_create);
    mu_run_test(test_slap);
    mu_run_test(test_shift);
    mu_run_test(test_pop);
    mu_run_test(test_slice);
    mu_run_test(test_for_forwards);
    mu_run_test(test_for_backwards);
    mu_run_test(test_length);
    //mu_run_test(test_clear);
    //mu_run_test(test_destroy);

    return NULL;
}

RUN_TESTS(all_tests);
