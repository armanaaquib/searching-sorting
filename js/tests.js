const assert = require('assert');
const { selectionSort } = require('./selectionSort');

describe('selectionSort', function () {
  it('should sort empty list', function () {
    assert.deepStrictEqual(selectionSort([]), []);
  });

  it('should sort sorted list', function () {
    assert.deepStrictEqual(selectionSort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5]);
  });

  it('should sort unsorted list', function () {
    assert.deepStrictEqual(selectionSort([5, 2, 3, 1, 0]), [0, 1, 2, 3, 5]);
  });
});
