from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout


class Repo1Conan(ConanFile):
    name = "repo1"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    options = {"with_tests": [True, False]}
    default_options = {"with_tests": False}

    def build_requirements(self):
        if self.options.with_tests:
            self.test_requires("gtest/1.15.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.cache_variables["BUILD_TESTING"] = "ON" if self.options.with_tests else "OFF"
        tc.generate()
        CMakeDeps(self).generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if self.options.with_tests:
            cmake.test()