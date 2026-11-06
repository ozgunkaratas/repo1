from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class Repo1Conan(ConanFile):
    name = "repo1"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def build_requirements(self):
        # test-only dependency: never shipped with the app
        self.test_requires("gtest/1.15.0")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()  # runs CTest; skipped when tools.build:skip_test=True