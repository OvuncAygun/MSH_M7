#ifndef ICOMMAND_H
#define ICOMMAND_H

// Temel Komut Arayüzü
class ICommand {
public:
    virtual ~ICommand() {}
    virtual void execute() = 0;
};

#endif // ICOMMAND_H