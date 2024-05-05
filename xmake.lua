add_requires("unity_test")

target("library")
    set_kind("shared")
    add_includedirs("include")
    add_files("src/**/*.c")

for _, file in ipairs(os.files("tests/test_*.c")) do
    local name = path.basename(file)
    target(name)
        set_kind("binary")
        set_default(false)
        add_files(file)
        add_includedirs("include")
        add_deps("library")
        add_packages("unity_test")
        add_cflags("-Wno-parentheses-equality")
        add_tests("default")
end