
"""
Create dictionary-like object holding a Conan profile configuration (ini-style).
Object initialization reads the config from disk and keeps it in mutable state in memory.
Object.save() writes the current state of the object back to the same file on disk.

Janus, July 2023.
"""

import configparser


class ConanProfile:

    def __init__(self, filename):
        """Loads configuration settings from file with filename (full path)."""
        self.filename: str = filename
        self.config = configparser.ConfigParser()
        self.config.read(filename)

    def __getitem__(self, section):
        """Returns a configuration section."""
        return self.config[section]
    
    def save(self) -> None:
        """Save current state of configuration to disk."""
        with open(self.filename, "w") as configfile:
            self.config.write(configfile)


def test():
    ce = ConanProfile("/root/.conan2/profiles/default")
    ce['settings']['arch'] = "x86_64xtest"
    ce.save()
