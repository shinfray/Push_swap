#include "push_swap.h"
// #include "push_swap.h"

// static size_t   ft_partition(t_dllist *stack_a, t_dllist *stack_b, int start, int end);

// void    ft_quicksort(t_dllist *stack_a, t_dllist *stack_b, int start, int end)
// {
//     int pivot;

//     if (end <= start)
//         return ;
//     pivot = partition(stack_a, stack_b, start, end);
//     ft_quicksort(stack_a, stack_b, start, pivot - 1);
//     ft_quicksort(stack_a, stack_b, pivot + 1, end);
// }

// static size_t   ft_partition(t_dllist *stack_a, t_dllist *stack_b, int start, int end)
// {
//     int  pivot;
//     t_dllist_node   *i_node;
//     t_dllist_node   *end_node;
//     t_dllist_node   *start_node;

//     start_node = ft_dllist_first(stack_a);
//     end_node = ft_dllist_last(stack_a);
//     while (start_node->place != start)
//     {
//         start_node = ft_dllist_next(start_node);
//         if (start_node = stack_a->sentinel_node)
//             start_node = ft_dllist_next(start_node);
//     }
//     while (end_node->place != end)
//     {
//         end_node = ft_dllist_next(end_node);
//         if (end_node = stack_a->sentinel_node)
//             end_node = ft_dllist_next(end_node);
//     }
//     pivot = end_node->val;



//     i_node = ft_dllist_prev(start_node);
//     if (i_node = stack_a->sentinel_node)
//         i_node = ft_dllist_prev(i_node);
//     while (ft_dllist_first(stack_a) != end_node)
//         ft_rra(stack_a, stack_b);
//     ft_pb(stack_a, stack_b);
//     while (start_node->place <= end_node->val - 1)
//     {
//         if (start_node->val < pivot)
//         {
//             i_node = ft_dllist_next(start_node);
//             if (i_node = stack_a->sentinel_node)
//                 i_node = ft_dllist_next(i_node);
            

//         }



//         start_node = ft_dllist_next(stack_a);
//         if (start_node = stack_a->sentinel_node)
//             start_node = ft_dllist_next(start_node);
//     }



// }
