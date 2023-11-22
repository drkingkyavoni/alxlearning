#!/usr/bin/python3
import unittest
from ..src.add_func import add

"""
    Testing module for addition function
"""


class TestAddition(unittest.TestCase):
    """
        Test class for addition function
    """

    def test_argument_type(self):
        with self.assertRaises(TypeError):
            add("a", 3)
            add(1, "a")
            add('a', 1)
            add({}, 1)
            add(1, {})

    def test_argument_value(self):
        with self.assertRaises(ValueError):
            add(None, 1)
            add(None, None)
            add(1, None)
            add(1, '')
            add('', '')
            add("", 1)
            add(1, "")
            add("", 'a')
            add('a', "")


if __name__ == "__main__":
    unittest.main()
