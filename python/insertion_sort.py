def insertion_sort(l):

  for i in range(1, len(l)):
    value = l[i]

    j = i - 1
    while j >= 0 and value < l[j]:
      l[j+1] = l[j]
      j -= 1

    l[j+1] = value

  return l
