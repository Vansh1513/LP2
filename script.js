function sendMessage() {

    // Input Box
    let inputBox = document.getElementById('userInput');


    // User Message
    let userMsg = inputBox.value;


    // Convert Message to Lowercase
    let msg = userMsg.toLowerCase();


    // Empty Message Validation
    if(userMsg == '') {

        alert("Please enter a message");

        return;
    }


    // Chat Box
    let chatBox = document.getElementById('chat-box');


    // Display User Message
    chatBox.innerHTML +=
        "<div class='user-message'>" +
        userMsg +
        "</div>";


    // Auto Scroll
    chatBox.scrollTop = chatBox.scrollHeight;


    // Bot Reply Variable
    let botReply = '';


    // Chatbot Conditions
    if(msg.includes('hii') || msg.includes('hello')) {

        botReply = "Hello, how can I help you today?";
    }
    else if(msg.includes('order')){
        botReply = "Sure, I can help you with your order. What would you like to order?";
    }
    else if(msg.includes('refund')){
        botReply = "I understand you want a refund. Can you please provide your order number?";
    }
    else if(msg.includes('payment')){
        botReply = "I can assist you with payment issues. What seems to be the problem?";
    }
    else if(msg.includes('delivery')){
        botReply = "I can help you with delivery information. Can you please provide your order number?";
    }
    else if(msg.includes('thank you')){
        botReply = "You're welcome! Is there anything else I can help you with?";
    }
    else{
        botReply="Sorry,I did not understand";
    }

    // Display Bot Message
    chatBox.innerHTML +=
        "<div class='bot-message'>" +
        botReply +
        "</div>";


    // Auto Scroll
    chatBox.scrollTop = chatBox.scrollHeight;


    // Clear Input Box
    inputBox.value = '';
}