let count;

const sorter = function (el1, el2) {
  count += 1;
  return el1 - el2;
};

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
    while ((count += 1) && j >= 0 && key < list[j]) {
      list[j + 1] = list[j];
      j -= 1;
    }

    list[j + 1] = key;
  }
};

// const quickSort = function (list, start, end) {
//   if (end <= start) return;

//   let pivot_idx = end;
//   let last_smaller_idx = start;

//   for (let j = start; j <= end; j++) {
//     count += 1;
//     if (list[j] < list[pivot_idx]) {
//       const temp = list[j];
//       list[j] = list[last_smaller_idx];
//       list[last_smaller_idx] = temp;

//       last_smaller_idx += 1;
//     }
//   }
//   const temp = list[last_smaller_idx];
//   list[last_smaller_idx] = list[pivot_idx];
//   list[pivot_idx] = temp;

//   pivot_idx = last_smaller_idx;

//   quickSort(list, start, pivot_idx - 1);
//   quickSort(list, pivot_idx + 1, end);
// };

const quickSort = function (list, low, high) {
  if (high <= low) return;

  const pivot = list[Math.floor((low + high) / 2)];

  let i = low;
  let j = high;

  while (i < j) {
    while (list[i] < pivot && (count += 1)) i += 1;
    while (list[j] > pivot && (count += 1)) j -= 1;

    if (i < j) {
      const temp = list[i];
      list[i] = list[j];
      list[j] = temp;
      i += 1;
      j -= 1;
    }
  }

  quickSort(list, low, j);
  quickSort(list, j + 1, high);
};

const quickNotInPlaceSort = function (list) {
  if (list.length <= 1) return list;

  const pivot = list[list.length - 1];

  const left = [];
  const right = [];

  for (let el of list.slice(0, list.length - 1)) {
    count += 1;
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

const findPos = function (list, start, end, el) {
  if (start > end) {
    return start;
  }

  const midIdx = Math.ceil((start + end) / 2);

  count += 1;
  console.log(el, list[midIdx]);
  if (el < list[midIdx]) {
    return findPos(list, start, midIdx - 1, el);
  } else {
    return findPos(list, midIdx + 1, end, el);
  }
};

const shiftRight = function (list, fromIdx, tillIdx) {
  for (let i = tillIdx - 1; i >= fromIdx; i--) {
    list[i + 1] = list[i];
  }
};

const startInsertionSort = function (list, startIndx) {
  for (let i = startIndx; i < list.length; i++) {
    const key = list[i];
    const indx = findPos(list, 0, i - 1, key);
    shiftRight(list, indx, i);
    list[indx] = key;
  }
};

const sortAsRevSorted = function (list) {
  for (let i = 1; i < list.length; i++) {
    count += 1;
    if (list[i] >= list[0]) {
      return startInsertionSort(list, i);
    }

    const key = list[i];
    shiftRight(list, 0, i);
    list[0] = key;
  }
};

const sortAsSorted = function (list) {
  for (let i = 1; i < list.length; i++) {
    count += 1;
    if (list[i] < list[i - 1]) {
      return startInsertionSort(list, i);
    }
  }
};

const jsSort = function (list) {
  if (list.length <= 1) {
    return;
  }

  if (list[0] <= list[1]) {
    sortAsSorted(list);
  } else {
    sortAsRevSorted(list);
  }
};

const generateCounts = function (list) {
  caseDetail = {};

  console.log(list);
  count = 0;
  list.slice().sort(sorter);
  caseDetail.jsSort = count;

  count = 0;
  jsSort(list.slice());
  caseDetail.myJsSort = count;

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

  count = 0;
  quickNotInPlaceSort(list, 0, list.length - 1);
  caseDetail.quickNotInPlaceSort = count;

  return caseDetail;
};

const sortDetail = {};

const sortedList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
sortDetail[`sorted(${sortedList.length})`] = generateCounts(sortedList);

const revSortedList = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
sortDetail[`revSorted(${revSortedList.length})`] = generateCounts(
  revSortedList
);

const partiallySortedList = [1, 2, 3, 4, 7, 9, 6, 5, 10, 8];
sortDetail[
  `partiallySortedList(${partiallySortedList.length})`
] = generateCounts(partiallySortedList);

const unsortedList = [9, 2, 6, 3, 7, 10, 8, 4, 1, 5];
sortDetail[`unsortedList(${unsortedList.length})`] = generateCounts(
  unsortedList
);

console.table(sortDetail);
