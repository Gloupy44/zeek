# @TEST-EXEC: ${DIST}/aux/zeek-aux/plugin-support/init-plugin -u . Testing NoPatchVersion
# @TEST-EXEC: cp -r %DIR/plugin-nopatchversion-plugin/* .
# @TEST-EXEC: ./configure --bro-dist=${DIST} && make
# @TEST-EXEC: ZEEK_PLUGIN_PATH=$(pwd) zeek -N Testing::NoPatchVersion >> output
# @TEST-EXEC: btest-diff output
