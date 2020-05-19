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

module.exports = { insertionSort };
