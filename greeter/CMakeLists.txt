add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
  ${KDE4_INCLUDES}
  ${QLIGHTDM_INCLUDE_DIR}
  ${KDECLARATIVE_INCLUDE_DIR}
)

# Insert your sources here
set(GREETER_SRCS
    extrarowproxymodel.cpp
    faceimageprovider.cpp
    greeterwindow.cpp
    powermanagement.cpp
    main.cpp
    configwrapper.cpp
    sessionsmodel.cpp
    usersmodel.cpp
    screensmodel.cpp
    greeterwrapper.cpp
)

qt4_add_dbus_interface(GREETER_SRCS
    org.freedesktop.UPower.xml
    upower
)

# Create the greeter
kde4_add_executable(lightdm-kde-greeter ${GREETER_SRCS})

# Link against the needed libraries
target_link_libraries(lightdm-kde-greeter
  ${QT_QTDECLARATIVE_LIBRARY}
  ${KDE4_KDEUI_LIBS}
  ${KDE4_PLASMA_LIBS}
  ${QLIGHTDM_LIBRARIES}
  ${KDECLARATIVE_LIBRARIES}
)

install(TARGETS lightdm-kde-greeter RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/sbin/)
install(FILES lightdm-kde-greeter.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/xgreeters)

# Create the background hack
kde4_add_executable(lightdm-kde-greeter-rootimage rootimageapp.cpp)
target_link_libraries(lightdm-kde-greeter-rootimage ${KDE4_KDEUI_LIBS} ${X11_X11_LIB})
install(TARGETS lightdm-kde-greeter-rootimage DESTINATION ${LIBEXEC_INSTALL_DIR})

macro_display_feature_log()


