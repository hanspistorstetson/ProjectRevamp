module EventsHelper
  def datepicker_input form, field
    content_tag :td, :data => {:provide => 'datepicker', 'date-format' => 'yyyy-mm-dd', 'date-autoclose' => 'true'} do
      form.text_field field, class: 'form-control', placeholder: 'YYYY-MM-DD'
    end
  end

  def create_signup user_id, event_id
    Signup.create(user_id: user_id, event_id: event_id)
    flash[:success] = "You have successfully signed up for " + @event.title

  end

end
