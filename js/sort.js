const selectionSort = function (list) {
  for (let i = 0; i < list.length - 1; i++) {
    let minItmIdx = i;

    for (let j = i + 1; j < list.length; j++) {
      if (list[j] < list[minItmIdx]) minItmIdx = j;
    }

    const temp = list[i];
    list[i] = list[minItmIdx];
    list[minItmIdx] = temp;
  }
};

const bubbleSort = function (list) {
  for (let i = 0; i < list.length; i++) {
    let swap = false;

    for (let j = 0; j < list.length - i - 1; j++) {
      if (list[j] > list[j + 1]) {
        const temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
        swap = true;
      }
    }

    if (swap === false) break;
  }
};

const insertionSort = function (list) {
  for (let i = 1; i < list.length; i++) {
    const key = list[i];

    let j = i - 1;
    while (j >= 0 && key < list[j]) {
      list[j + 1] = list[j];
      j -= 1;
    }

    list[j + 1] = key;
  }
};

const quickNotInPlaceSort = function (list) {
  if (list.length <= 1) return list;

  const pivot = list[list.length - 1];

  const left = [];
  const right = [];

  for (let el of list.slice(0, list.length - 1)) {
    if (el <= pivot) {
      left.push(el);
    } else {
      right.push(el);
    }
  }

  return quickNotInPlaceSort(left)
    .concat(pivot)
    .concat(quickNotInPlaceSort(right));
};

const quickSort = function (list, start, end) {
  if (end <= start) return;

  let pivot_idx = end;
  let last_smaller_idx = start;

  for (let j = start; j <= end; j++) {
    if (list[j] < list[pivot_idx]) {
      const temp = list[j];
      list[j] = list[last_smaller_idx];
      list[last_smaller_idx] = temp;

      last_smaller_idx += 1;
    }
  }
  const temp = list[last_smaller_idx];
  list[last_smaller_idx] = list[pivot_idx];
  list[pivot_idx] = temp;

  pivot_idx = last_smaller_idx;

  quickSort(list, start, pivot_idx - 1);
  quickSort(list, pivot_idx + 1, end);
};

module.exports = {
  selectionSort,
  bubbleSort,
  insertionSort,
  quickSort,
  quickNotInPlaceSort,
};
