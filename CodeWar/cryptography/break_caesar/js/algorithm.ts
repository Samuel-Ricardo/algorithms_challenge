function breakCaesar(st) {
  let alphabet = [
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
  ];

  let result = "";
  let n = 0;

  let notInWORDS = true;

  while (notInWORDS) {
    n++;

    let words = [""];

    words = st
      .toLowerCase()
      .split(" ")
      .map((word) => {
        result = "";
        word.split("").forEach((letter) => {
          if (alphabet.includes(letter)) {
            const unshift =
              alphabet[alphabet.indexOf(letter) + alphabet.length / 2 - n];
            console.log({ unshift });
            result = result.concat(unshift);
          }
        });

        return result;
      });

    console.log({ result, words });

    const match = words.filter((word) => WORDS.has(word));

    if (match.length === words.length) notInWORDS = false;
  }

  return n;
}
