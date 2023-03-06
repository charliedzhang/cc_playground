from conans import CMake, ConanFile, tools

class CcPlaygroud(ConanFile):
    name = "cc_playground"
    version = "0.1.0"
    description = ""

    settings = "os", "compiler", "build_type", "arch", "cppstd"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    requires = (
        "gtest/1.13.0",
        "systemc/2.3.3",
    )

    exports_sources = (
        "src/*",
        "test/*",
        "CMakeLists.txt",
    )
    generators = "cmake", "cmake_find_package"

    __cmake = None

    @property
    def _cmake(self):
        if self.__cmake is None:
            self.__cmake = CMake(self)
        return self.__cmake

    def build(self):
        self._cmake.generator="Ninja"
        self._cmake.configure(source_dir=self.source_folder)
        self._cmake.build()
        if tools.get_env("CONAN_RUN_TESTS", True):
            self._cmake.test()

    def package(self):
        self._cmake.install()

    def package_info(self):
        self.cpp_info.names["cmake_find_package"] = "cc_playground"
        self.cpp_info.components["_build"].requires = ["gtest::gtest"]
        self.cpp_info.components["libcc_playground"].names["cmake_find_package"] = "cc_playground"
        self.cpp_info.components["libcc_playground"].libs = ["cc_playground"]
