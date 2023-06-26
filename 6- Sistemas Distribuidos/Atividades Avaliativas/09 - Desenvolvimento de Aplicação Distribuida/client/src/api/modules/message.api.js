import privateClient from '../client/private.client';

const messageEndpoints = {
    fetchMessages: ({ chatId }) => `/message/${chatId}`,
    sendMessage: '/message',
}

const messageApi = {
    fetchMessages: async ({ chatId }) => {
        try {
            const response = await privateClient.get(
                messageEndpoints.fetchMessages({ chatId })
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    sendMessage: async ({ content, chatId }) => {
        try {
            const response = await privateClient.post(
                messageEndpoints.sendMessage, {
                    content,
                    chatId
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    }
}


export default messageApi;