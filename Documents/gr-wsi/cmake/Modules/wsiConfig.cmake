INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_WSI wsi)

FIND_PATH(
    WSI_INCLUDE_DIRS
    NAMES wsi/api.h
    HINTS $ENV{WSI_DIR}/include
        ${PC_WSI_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    WSI_LIBRARIES
    NAMES gnuradio-wsi
    HINTS $ENV{WSI_DIR}/lib
        ${PC_WSI_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(WSI DEFAULT_MSG WSI_LIBRARIES WSI_INCLUDE_DIRS)
MARK_AS_ADVANCED(WSI_LIBRARIES WSI_INCLUDE_DIRS)

