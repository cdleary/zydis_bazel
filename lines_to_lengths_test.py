import subprocess
import textwrap
import unittest

from tools.python.runfiles import runfiles


class LinesToLengthsTest(unittest.TestCase):

    def test_examples_with_useless_suffixes(self):
        text = textwrap.dedent("""
        90
        90 00
        41 50
        41 50 01
        """).strip()
        r = runfiles.Create()
        results = subprocess.check_output(
            [r.Rlocation('zydis_bazel/lines_to_lengths')],
            input=text.encode('utf-8'),
        ).decode('utf-8')
        self.assertEqual(results.splitlines(), ['1', '1', '2', '2'])


if __name__ == '__main__':
    unittest.main()
