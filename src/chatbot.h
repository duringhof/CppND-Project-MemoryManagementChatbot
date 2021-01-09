#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot {
  
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                                  // constructor WITHOUT memory allocation
    ChatBot(std::string filename);              // constructor WITH memory allocation
    ~ChatBot();                                 // destructor (rule 1 of 5)
    ChatBot(const ChatBot &source);             // copy constructor (rule 2 of 5)
    ChatBot &operator=(const ChatBot &source);  // copy assignment operator (rule 3 of 5)
    ChatBot(ChatBot &&source);                  // move constructor (rule 4 of 5)
    ChatBot &operator=(ChatBot &&source);       // move assignment operator (rule 5 of 5)
    
    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */