#We want to expose our new config widgets, but because we use QUiLoader we need a QtPlugin to explain how to load/create them.
#We build a static version of this QtPlugin then the KCM includes this, and uses Q_IMPORT_PLUGIN to reference it.
#alternately we could install this as an additional library, but that seems extra complicated.


# Insert your sources here
set(LIGHTDM_CONFIG_WIDGET_SRCS
    selectimagebutton.cpp
    selectimagebuttondesignerfactory.cpp
)

#not sure if this is a bad hack, CMake made me do it
add_definitions(-fPIC)

kde4_add_plugin(lightdm_config_widgets STATIC
                ${LIGHTDM_CONFIG_WIDGET_SRCS})

# Link against the needed libraries
target_link_libraries(lightdm_config_widgets
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
)

#uncomment this if building a non-static version of this lib.
#install( TARGETS lightdm_config_widgets DESTINATION ${PLUGIN_INSTALL_DIR}/plugins/designer )
