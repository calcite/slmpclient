from setuptools import setup, Extension

with open("README.md", "r") as fh:
    long_description = fh.read()

c_module = Extension('slmpclient.clib.slmp_c',
                     include_dirs=['slmpclient/clib/include'],
                     sources=['slmpclient/clib/src/SLMP.c'])


setup(
    name='slmpclient',
    version='2.0.0',
    packages=['slmpclient'],
    author='Roland Zitny',
    long_description=long_description,
    long_description_content_type="text/markdown",
    ext_modules=[c_module],
)
