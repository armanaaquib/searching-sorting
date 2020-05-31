const linearSearch = function (list, searchKey) {
  for (let i = 0; i < list.length; i++) {
    if (searchKey == list[i]) {
      return i;
    }
  }

  return -1;
};

const _binarySearch = function (list, start, end, searchKey) {
  if (end < start) {
    return -1;
  }

  const midIdx = Math.floor((start + end) / 2);

  if (searchKey == list[midIdx]) {
    return midIdx;
  }

  if (searchKey < list[midIdx]) {
    return _binarySearch(list, start, midIdx - 1, searchKey);
  }

  return _binarySearch(list, midIdx + 1, end, searchKey);
};

const binarySearch = function (list, searchKey) {
  return _binarySearch(list, 0, list.length - 1, searchKey);
};

module.exports = { linearSearch, binarySearch };
