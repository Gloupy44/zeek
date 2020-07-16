// See the file "COPYING" in the main distribution directory for copyright.

#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace zeek::packet_analysis {

class DispatcherConfig {
public:
	explicit DispatcherConfig(const std::string name) : name(std::move(name)) { }

	const std::string& GetName() const;
	const std::map<uint32_t, std::string>& GetMappings() const;

	void AddMapping(uint32_t identifier, const std::string& analyzer_name);

	bool operator==(const DispatcherConfig& rhs) const;
	bool operator!=(const DispatcherConfig& rhs) const;

private:
	const std::string name;
	std::map<uint32_t, std::string> mappings;
};

class Config {

public:
	const std::vector<DispatcherConfig>& GetDispatchers() const;
	std::optional<std::reference_wrapper<DispatcherConfig>> GetDispatcherConfig(const std::string& name);
	DispatcherConfig& AddDispatcherConfig(const std::string& name);
	void AddMapping(const std::string& name, uint32_t identifier, const std::string& analyzer_name);

private:
	std::vector<DispatcherConfig> dispatchers;
};

}
