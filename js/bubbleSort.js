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

module.exports = { bubbleSort };
