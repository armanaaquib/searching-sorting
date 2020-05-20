const selectionSort = function (list) {
  for (let i = 0; i < list.length - 1; i++) {
    min_itm_idx = i;

    for (let j = i + 1; j < list.length; j++) {
      if (list[j] < list[min_itm_idx]) min_itm_idx = j;
    }

    temp = list[i];
    list[i] = list[min_itm_idx];
    list[min_itm_idx] = temp;
  }

  return list;
};

const bubbleSort = function (list) {
  for (let i = 0; i < list.length; i++) {
    swap = false;

    for (let j = 0; j < list.length - i - 1; j++) {
      if (list[j] > list[j + 1]) {
        temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
        swap = true;
      }
    }

    if (swap === false) break;
  }
  return list;
};

const insertionSort = function (list) {
  for (let i = 1; i < list.length; i++) {
    key = list[i];

    j = i - 1;
    while (j >= 0 && key < list[j]) {
      list[j + 1] = list[j];
      j -= 1;
    }

    list[j + 1] = key;
  }

  return list;
};

module.exports = { selectionSort, bubbleSort, insertionSort };
