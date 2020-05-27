let count;

const selectionSort = function (list) {
  for (let i = 0; i < list.length - 1; i++) {
    let minItmIdx = i;

    for (let j = i + 1; j < list.length; j++) {
      count += 1;
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
      count += 1;
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
  for (i = 1; i < list.length; i++) {
    const key = list[i];

    let j = i - 1;
    while (j >= 0 && key < list[j]) {
      count += 1;
      list[j + 1] = list[j];
      j -= 1;
    }

    list[j + 1] = key;
  }
};

const quickSort = function (list, start, end) {
  if (end <= start) return;

  let pivot_idx = end;
  let last_smaller_idx = start;

  for (let j = start; j <= end; j++) {
    count += 1;
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

const generateCounts = function (list) {
  caseDetail = {};

  count = 0;
  selectionSort(list.slice());
  caseDetail.selectionSort = count;

  count = 0;
  bubbleSort(list.slice());
  caseDetail.bubbleSort = count;

  count = 0;
  insertionSort(list.slice());
  caseDetail.insertionSort = count;

  count = 0;
  quickSort(list.slice(), 0, list.length - 1);
  caseDetail.quickSort = count;

  return caseDetail;
};

const sortDetail = {};

const sortedList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
sortDetail[`sorted(${sortedList.length})`] = generateCounts(sortedList);

const partiallySortedList = [1, 2, 3, 4, 7, 9, 6, 5, 10, 8];
sortDetail[
  `partiallySortedList(${partiallySortedList.length})`
] = generateCounts(partiallySortedList);

const unsortedList = [9, 2, 6, 3, 7, 10, 8, 4, 1, 5];
sortDetail[`UnsortedList(${unsortedList.length})`] = generateCounts(
  unsortedList
);

console.table(sortDetail);
