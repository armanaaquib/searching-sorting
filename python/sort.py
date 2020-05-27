def selection_sort(l):

    for i in range(len(l) - 1):
        min_itm_idx = i

        for j in range(i + 1, len(l)):
            if l[j] < l[min_itm_idx]:
                min_itm_idx = j

        l[i], l[min_itm_idx] = l[min_itm_idx], l[i]


def bubble_sort(l):

    for i in range(len(l)):
        swap = False

        for j in range(len(l) - i - 1):
            if l[j] > l[j+1]:
                l[j], l[j+1] = l[j+1], l[j]
                swap = True

        if swap is False:
            break


def insertion_sort(l):

    for i in range(1, len(l)):
        key = l[i]

        j = i - 1
        while j >= 0 and key < l[j]:
            l[j+1] = l[j]
            j -= 1

        l[j+1] = key


def quick_not_in_place_sort(l):
    if len(l) <= 1:
        return l

    pivot = l[-1]

    left = []
    right = []

    for el in l[:-1]:
        if el <= pivot:
            left.append(el)
        else:
            right.append(el)

    return quick_not_in_place_sort(left) + [pivot] + quick_not_in_place_sort(right)


'''
shifting to insert in place
def quick_sort(l, start, end):
    if end <= start:
        return

    pivot_idx = start

    for i in range(start + 1, end + 1):
        if l[i] < l[pivot_idx]:
            key = l[i]
            j = i - 1
            while j >= pivot_idx:
                l[j + 1] = l[j]
                j -= 1

            l[pivot_idx] = key
            pivot_idx += 1

    quick_sort(l, start, pivot_idx - 1)
    quick_sort(l, pivot_idx + 1, end)
'''


def quick_sort(l, start, end):
    if end <= start:
        return

    pivot_idx = end

    last_smaller_idx = start

    for j in range(start, end):
        if l[j] < l[pivot_idx]:

            l[j], l[last_smaller_idx] = l[last_smaller_idx], l[j]
            last_smaller_idx += 1

    l[last_smaller_idx], l[pivot_idx] = l[pivot_idx], l[last_smaller_idx]
    pivot_idx = last_smaller_idx

    quick_sort(l, start, pivot_idx - 1)
    quick_sort(l, pivot_idx + 1, end)
