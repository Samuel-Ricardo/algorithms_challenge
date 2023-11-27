function twoSum(nums: number[], target: number): number[] {
  const result: number[] = [];
  let where = null;

  nums.some((item, index) => {
    const sum = nums.filter((num, position) => {
      const result = index !== position && item + num === target;
      if (result) where = position;
      return result;
    });
    return sum.length > 0 ? result.push(index, where) : false;
  });

  return result;
}
