#include "push_swap.h"

void    ft_insertion_sort(t_dllist *stack_a, t_dllist *stack_b);
// void	ft_print_stack(t_dllist *stack_a, t_dllist *stack_b);
void    ft_sort_small_list(t_dllist *stack_a);

bool    ft_calcul_ra_rra(t_dllist *stack, t_dllist_node *current)
{
    t_dllist_node    *save;
    int ra;
    int rra;

    save = current;
    ra = 0;
    rra = 0;
    while (current != stack->sentinel_node)
    {
        current = ft_dllist_next(current);
        ++ra;
    }
    current = save;
    while (current != stack->sentinel_node)
    {
        current = ft_dllist_prev(current);
        ++rra;
    }
    if (ra < rra)
        return (0);
    return (1);
}

void    ft_insertion_sort(t_dllist *stack_a, t_dllist *stack_b)
{
    int tot_nod;
    t_dllist_node   *current_node;
    t_dllist_node   *next_current_node;
    t_dllist_node   *last_node;
    bool            ra_rra;
    t_dllist_node        *temp;

    if (stack_a->total_nodes <= 3)
    {
        ft_sort_small_list(stack_a);
        return ;
    }
    tot_nod = stack_a->total_nodes;
    current_node = ft_dllist_next(ft_dllist_first(stack_a));
    next_current_node = ft_dllist_next(current_node);
    last_node = ft_dllist_last(stack_a);
    while (tot_nod-- > 1)
    {
        if (ft_dllist_prev(current_node)->val > current_node->val)
        {
            ra_rra = ft_calcul_ra_rra(stack_a, current_node);
            while (current_node != ft_dllist_first(stack_a))
            {
                if (ra_rra == 0)
                    ft_ra(stack_a, stack_b);
                else
                    ft_rra(stack_a, stack_b);
            }
            ft_pb(stack_a, stack_b);
            while (ft_dllist_first(stack_b)->val < ft_dllist_last(stack_a)->val && ft_dllist_last(stack_a) != last_node)
                ft_rra(stack_a, stack_b);
            ft_pa(stack_a, stack_b);
        }
        current_node = next_current_node;
        next_current_node = ft_dllist_next(current_node);
    }
    current_node = ft_dllist_first(stack_a);
    temp = ft_dllist_next(current_node);
    while (temp != stack_a->sentinel_node)
    {
        if (temp->val < current_node->val)
            current_node = current_node->next;
        temp = temp->next;
    }
    ra_rra = ft_calcul_ra_rra(stack_a, current_node);
    while (ft_dllist_last(stack_a)->val < ft_dllist_first(stack_a)->val)
    {
        if (ra_rra == 0)
            ft_ra(stack_a, stack_b);
        else
            ft_rra(stack_a, stack_b);
    }
}

void    ft_sort_small_list(t_dllist *stack_a)
{
    const int   a = ft_dllist_first(stack_a)->val;
    const int   b = ft_dllist_next(ft_dllist_first(stack_a))->val;
    const int   c = ft_dllist_last(stack_a)->val;

    if (stack_a->total_nodes == 2)
            ft_sa(stack_a, NULL);
    else if (a > b && b < c && c > a)
        ft_sa(stack_a, NULL);
    else if (a > b && b > c)
    {
        ft_sa(stack_a, NULL);
        ft_rra(stack_a, NULL);
    }
    else if (a > b && b < c && c < a)
        ft_ra(stack_a, NULL);
    else if (a < b && b > c && c > a)
    {
        ft_sa(stack_a, NULL);
        ft_ra(stack_a, NULL);
    }
    else if (a < b && b > c && c < a)
        ft_rra(stack_a, NULL);
}
