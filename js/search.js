const linearSearch = function (list, searchKey) {
  let pos = 0;

  for (let i = 0; i < list.length; i++) {
    if (searchKey == list[i]) {
      return pos;
    }

    pos += 1;
  }

  return -1;
};

module.exports = { linearSearch };
