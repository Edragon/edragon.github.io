
# stripe-dat 

## 3D Secure authentication

3D Secure (3DS) is an authentication method that provides an additional layer of authentication for credit card transactions, to protect against fraudulent actors. 


## The customer failed to authenticate with 3D Secure - 🛠️ Action Items

error log: 

    3D Secure attempt failed 
    The cardholder attempted 3D Secure authentication 3 times. 
    Payment failed

### 🔄 For You (Merchant):

1. **Do not retry** the same PaymentIntent as-is — Stripe has already marked it as failed (`status: requires_payment_method`).
2. Instead, prompt the customer to:
   - Use a different card.
   - Try again and **complete 3D Secure properly**.
3. Consider implementing Stripe’s [`automatic_payment_methods`](https://stripe.com/docs/payments/automatic-payment-methods/overview) so Stripe can intelligently select the best payment path.
4. Optionally send a link to [Stripe’s help page on 3D Secure](https://stripe.com/docs/strong-customer-authentication) if the customer is confused.

### 📞 For Customer:

- Contact their **bank** to ensure 3D Secure is set up and functioning on their card.
- Try a **different browser or network** (e.g., avoid browser extensions that may block Stripe popups).
- Or **use another card**.




## ref 

- [[stripe]]


