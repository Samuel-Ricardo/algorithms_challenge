The Caesar cipher is a notorious (and notoriously simple) algorithm for encrypting a message: each letter is shifted a certain constant number of places in the alphabet. For example, applying a shift of 5 to the string "Hello, world!" yields "Mjqqt, btwqi!", which is jibberish.

In this kata, your task is to decrypt Caesar-encrypted messages using nothing but your wits, your computer, and a set of the 1000 (plus a few) most common words in English in lowercase (made available to you as a preloaded variable named WORDS, which you may use in your code as if you had defined it yourself).

Given a message, your function must return the most likely shift value as an integer.
A few hints:

Be wary of punctuation
Shift values may not be higher than 25

```js
const chai = require("chai");
const assert = chai.assert;

describe("Example cases", function () {
  it("basic tests", function () {
    assert.strictEqual(breakCaesar("DAM?"), 7);
    assert.strictEqual(breakCaesar("Mjqqt, btwqi!"), 5);
    assert.strictEqual(
      breakCaesar("Gur dhvpx oebja sbk whzcf bire gur ynml qbt."),
      13
    );
  });
});
```
