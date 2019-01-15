
algorithm quicksort(A, lo, hi) is
    if lo < hi then
        p := partition(A, lo, hi)
        quicksort(A, lo, p - 1)
        quicksort(A, p + 1, hi)

algorithm partition(A, lo, hi) is
    pivot := A[hi]
    i := lo
    for j := lo to hi - 1 do
        if A[j] < pivot then
            if i != j then
                swap A[i] with A[j]
            i := i + 1
    swap A[i] with A[hi]
    return i

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

t_dlist *partition(t_dlist *stack, t_dlist *lo, t_dlist *hi)
{
    t_dlist *pivot = hi;
    t_dlist *it = lo;
    for (t_dlist *j = lo; j != hi->prev; j = j->next)
        if (*(int *)j->content < *(int *)pivot->content)
        {
            if (it != j)
                swap(it->content, j->content);
            it = it->next;
        }
    swap(it->content, hi->content);
    return (it);
}

void quicksort(t_dlist *stack, t_dlist *lo, t_dlist *hi)
{
    if (lo == hi || lo == stack || hi == stack)
        return ;
    t_dlist *p = partition(stack, lo, hi);
    quicksort(stack, lo, hi);
    quicksort(stack, p->next, hi);
}
