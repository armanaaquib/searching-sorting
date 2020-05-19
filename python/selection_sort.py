def selection_sort(l):

  for i in range(len(l) - 1):
    min_itm_idx = i

    for j in range(i + 1, len(l)):
      if l[j] < l[min_itm_idx]:
        min_itm_idx = j

    l[i], l[min_itm_idx] = l[min_itm_idx], l[i]

  return l
