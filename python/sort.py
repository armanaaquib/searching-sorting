def selection_sort(l):

    for i in range(len(l) - 1):
        min_itm_idx = i

        for j in range(i + 1, len(l)):
            if l[j] < l[min_itm_idx]:
                min_itm_idx = j

        l[i], l[min_itm_idx] = l[min_itm_idx], l[i]

    return l


def bubble_sort(l):

    for i in range(len(l)):
        swap = False

        for j in range(len(l) - i - 1):
            if l[j] > l[j+1]:
                l[j], l[j+1] = l[j+1], l[j]
                swap = True

        if swap is False:
            break

    return l


def insertion_sort(l):

    for i in range(1, len(l)):
        key = l[i]

        j = i - 1
        while j >= 0 and key < l[j]:
            l[j+1] = l[j]
            j -= 1

        l[j+1] = key

    return l


def quick_sort(l):
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

    return quick_sort(left) + [pivot] + quick_sort(right)
