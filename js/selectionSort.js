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

module.exports = { selectionSort };
